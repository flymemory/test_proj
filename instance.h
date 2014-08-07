#ifndef __INSTANCE_H_INCLUDE_
#define __INSTANCE_H_INCLUDE_

class instance
{
protected:
	int m_handle;

	module* m_module;
	message_queue *m_msgQueue;

public:
	virtual processMsg(void *param);
};


#endif