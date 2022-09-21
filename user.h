#ifndef USER_H
#define USER_H

// need class and not struct cause String^ has to be managed
public ref class User {
public:
	int id;
	System::String^ username;
	System::String^ password;
};

#endif // USER_H