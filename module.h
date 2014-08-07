#ifndef __MODULE_H_INCLUDE_
#define __MODULE_H_INCLUDE_

class module
{
private:
	int m_handle;

public:
	module();
	virtual ~module();

	virtual bool init()=0;
	virtual void release()=0;
	virtual void process()=0;
};

#endif
