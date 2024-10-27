#include"message.h"
#include"user.h"


int main() {
	string nme;
	string lgn;
	string psw;
	string txt;
	string sdr;
	string rcvr;
	fstream user_file = fstream("users.txt", ios::in | ios::out);
	if (!user_file)
		// Для создания файла используем параметр ios::trunc
		user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
	cout << "Enter name" << endl;
	cin >> nme;
	cout << "Enter login" << endl;
	cin >> lgn;
	cout << "Enter password" << endl;
	cin >> psw;
	if (user_file) {
		User obj(nme, lgn, psw);
		// Запишем данные по в файл
		user_file << obj << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		user_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
	
	}

	fstream message_file = fstream("message.txt", ios::in | ios::out);
	if (!message_file)
		// Для создания файла используем параметр ios::trunc
		message_file = fstream("message.txt", ios::in | ios::out | ios::trunc);
	cout << "Enter text" << endl;
	cin >> txt;
	cout << "Enter sender" << endl;
	cin >> sdr;
	cout << "Enter rcvr" << endl;
	cin >> rcvr;
	if (message_file) {
		Message obj (txt, sdr, rcvr);
		// Запишем данные по в файл
		message_file << obj << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		message_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		message_file >> obj;
		cout << obj << endl;
	}
	else
	{
		cout << "Could not open file message.txt !" << '\n';
		return 0;

	}
}
