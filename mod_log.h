#ifndef __MODULE_LOG_H_INCLUDE_
#define __MODULE_LOG_H_INCLUDE_


class log_mod_factory : public mod_factory
{
public:
	// Interface.
	virtual mod_instance* create();
	virtual void init( mod_instance* mod_inst, const char* param );
	virtual void release();
};


class log_mod : public mod_instance
{
public:
	virtual void dispath_msg();
	virtual void process( int type, int source, const void* msg, size_t sz );
};

#endif