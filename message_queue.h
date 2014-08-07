#ifndef __MESSAGE_QUEUE_H_INCLUDE_
#define __MESSAGE_QUEUE_H_INCLUDE_

struct message_entity
{
	void* data;
	size_t size;
};

class message_queue
{
public:
	message_queue();
	void release();

	void	push(message_entity* entity);
	int		pop(message_entity* out_msg);
	void	lock();
	void	unlock();

	int 	getLength();

	/** Sends messages to an handle.
	*/
	static void send_to();
	
protected:
	void _expand_queue();

private:
	int m_capacity;
	int m_head, m_tail;

	message_entity* msg_entities;
};

#endif

