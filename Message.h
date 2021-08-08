#ifndef K_CA_MESSAGE_H
#define K_CA_MESSAGE_H
#include "KCA.h"
#include "sha256.h"
#include <string>

 struct Message
{
	enum msg_type_t
	{
		REQUEST,
		CONFIRM,
		UNPACK
	}msg_type;

	std::string o;
	time_t t;
	network_address_t c = 0;
	std::string d;
	size_t v = 0;
	size_t n = 0;
	network_address_t i = 0;
        std::string m;


        explicit Message(msg_type_t _type);
        Message(const Message & msg);
        Message & operator=(const Message & msg);
	std::string diggest();
	std::string str() const;
};
#endif
