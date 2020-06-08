#include "Account.h"

Account::Account()
{
	create_id();
}

Account::Account(int start_dollars, int start_cents)
{
	assert(start_dollars >= 0 && start_cents >= 0);
	amount.add(start_dollars,start_cents);
	create_id();
}

void Account::create_id()
{
	for(int i=0; i<10; i++)
	{
		int digit = rand()%10;
		char char_digit = '0' + digit;
		account_id += char_digit;
	}
}

void Account::withdraw(int minus_dollars, int minus_cents)
{
	assert(minus_dollars*100+minus_cents <= 100*amount.get_dollars()+amount.get_cents());
	amount.sub(minus_dollars,minus_cents);
}

void Account::deposit(int add_dollars, int add_cents)
{
	amount.add(add_dollars,add_cents);
}

void Account::transfer_into(Account &destination, const Money &tr_amount)
{
	assert(amount.isBigger(tr_amount));
	destination.amount.add(tr_amount);
	amount.sub(tr_amount);
}

void Account::transfer_from(Account &source, const Money &tr_amount)
{
	assert(source.amount.isBigger(tr_amount));
	source.amount.sub(tr_amount);
	amount.add(tr_amount);
}

bool Account::is_valid(int sub_dollars, int sub_cents)
{
	if(sub_dollars*100+sub_cents <= amount.get_dollars()*100+amount.get_cents())
	{
		return true;
		cout << "Valid" << endl;
	}
	else
	{
		return false;
		cout << "Not Valid" << endl;
	}
}

bool Account::is_valid(const Money &sub_amount)
{
	if(sub_amount.get_dollars()*100+sub_amount.get_cents() <= amount.get_dollars()*100+amount.get_cents())
	{
		return true;
		cout << "Valid" << endl;
	}
	else
	{
		return false;
		cout << "Not Valid" << endl;
	}
}

void Account::display()
{
	cout << "ID: " << account_id << endl;
	amount.display();
}
