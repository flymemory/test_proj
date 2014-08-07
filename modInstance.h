#ifndef __MODULE_INSTANCE_H_INCLUDE_
#define __MODULE_INSTANCE_H_INCLUDE_

class mod_instance
{
	int m_handle;
	class message_queue* m_messages;
public:

	virtual void dispath_msg();
	virtual void process(int type, int source, const void* msg, size_t sz);
};

#endif