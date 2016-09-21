// Alex Schrepfer (CS151)
// University of Hawaii - Hilo
//
// This program takes advantage of doubly linked lists
// and has a user interface to test the functions
// the program will append, insert,clear,delete,replace
// fetch,traverse and returns the size
//
// 2001 April 24

#include   "../../C/UTILITY.H"
#include   "LIST.H"
#include   "LIST.CPP"
 
void write_entry(char &c) {
   cout << c;
}

void show_help() {
	cout << "------------------\n";
	cout << " A: Append        \n";
	cout << " I: Insert        \n";
	cout << " C: Clear         \n";
	cout << " D: Delete        \n";
	cout << " R: Replace       \n";
	cout << " F: Fetch         \n";
	cout << " T: Traverse      \n";
	cout << " S: Return size   \n";
	cout << " H: This Help     \n";
	cout << " Q: Quit          \n";
	cout << "------------------\n";
}

char get_command() {
	char cmd;
	bool waiting = true;
	cout << "#: ";

	while (waiting) {
		cin >> cmd;
		cmd = tolower(cmd);

		if (cmd == 'a' || cmd == 'i' || cmd == 'd' ||
			 cmd == 'r' || cmd == 'f' || cmd == 't' ||
			 cmd == 's' || cmd == 'h' || cmd == 'q' ||
			 cmd == 'c')	waiting = false;

		else
			show_help();
	}
	return cmd;
}

bool do_command(char cmd,List<char> &c_list) {

	char x;
	int i;
	switch(cmd) {
	case 'a':
		cout << "Append: ";
		cin >> x;
		c_list.insert(c_list.size(),x);
		break;
	case 'i':
		cout << "Insert what? ";
		cin >> x;
		cout << "Where? ";
		cin >> i;
		if (c_list.insert(i,x) != success)
			cout << "Error!" << endl;
		break;
	case 'd':
		cout << "Delete where? ";
		cin >> i;
		if (c_list.remove(i,x) != success)
			cout << "Error!" << endl;
		break;
	case 'r':
		cout << "Replace where? ";
		cin >> i;
		cout << "With what? ";
		cin >> x;
		if (c_list.replace(i,x) != success)
			 cout << "Error!" << endl;
		break;
	case 'f':
		cout << "Fetch where? ";
		cin >> i;
		if (c_list.retrieve(i,x) == success)
			cout << "Fetched " << x << " from " << i << endl;
		else
			cout << "Error!" << endl;
		break;
	case 't':
		cout << "Traverse: ";
		if (c_list.size())
			c_list.traverse(write_entry);
		else
			cout << "<empty>";
		cout << endl;
		break;
	case 's':
		cout << "Size: " << c_list.size() << endl;
		break;
	case 'h':
		show_help();
		break;
	case 'c':
		c_list.clear();
		cout << "List cleared." << endl;
		break;
	case 'q':
		return false;
		break;
	}
	return true;
}

void main() {

   List<char> c_list;

	cout << "Doubly Linked List Program and Tester\n"
		  << "Created Alex Schrepfer (CS151)\n\n";

	show_help();

	while (do_command(get_command(),c_list));

}


