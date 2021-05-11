#include "Message.h"

class Node;

class ViewState
{
	enum state_t
	{
		No_State,
		Prepared,
		Committed,
		Replyed,
	}state_;

	size_t accepeted_prepares = 0;
	size_t accepeted_commits= 0;

public:
	void handle_message(Message msg, Node & node);
};

