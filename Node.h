class Node;

class ViewState
{
	enum state_t
	{
		Requested,
		Prepared,
		committed,
		replyed,
	}state_;

	unsigned long accepeted_prepares = 0;
	unsigned long accepeted_commits= 0;

public:
	void handle_message(unsigned long msg, Node & node);
};

