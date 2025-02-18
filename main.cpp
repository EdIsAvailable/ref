#include"message.h"
#include"user.h"
#include <filesystem>
namespace fs = filesystem;

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
	// Ограничим права
        fs::permissions("users.txt",
	fs::perms::owner_all | fs::perms::group_all,
	fs::perm_options::replace);
        // запрос и ввод данных
	cout << "Enter name" << endl;
	cin >> nme;
	cout << "Enter login" << endl;
	cin >> lgn;
	cout << "Enter password" << endl;
	cin >> psw;
	if (user_file) {
		User usr(nme, lgn, psw);
		// Запишем данные по в файл
		user_file << usr << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		user_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		user_file >> usr;
		cout << usr << endl;
	}
	else
	{
		cout << "Could not open file users.txt !" << endl;
	
	}

	fstream message_file = fstream("message.txt", ios::in | ios::out);
	if (!message_file)
		// Для создания файла используем параметр ios::trunc
		message_file = fstream("message.txt", ios::in | ios::out | ios::trunc);
	// ограничим права
        fs::permissions("message.txt",
	fs::perms::owner_all | fs::perms::group_all,
	fs::perm_options::replace);

	cout << "Enter text" << endl;
	cin >> txt;
	cout << "Enter sender" << endl;
	cin >> sdr;
	cout << "Enter rcvr" << endl;
	cin >> rcvr;
	if (message_file) {
		Message msg (txt, sdr, rcvr);
		// Запишем данные по в файл
		message_file << msg << endl;
		// Чтобы считать данные из файла, надо установить позицию для чтения в начало файла
		message_file.seekg(0, ios_base::beg);
		// Считываем данные из файла
		message_file >> msg;
		cout << msg << endl;
	}
	else
	{
		cout << "Could not open file message.txt !" << endl;
		return 0;

	}
}
