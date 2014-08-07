#ifndef __MODULE_FACTORY_H_INCLUDE_
#define __MODULE_FACTORY_H_INCLUDE_

class mod_factory
{
protected:
	char* m_mod_name;

public:
	mod_factory(char *mod_name);
	
	/** Creates instance pointer.
	*/
	virtual mod_instance* create();
	/** Initializes instace environment.
	*/
	virtual void init(mod_instance* mod_inst, const char* param);
	/** Releases instance and environment.
	*/
	virtual void release();
};

class mod_factory_manager
{
public:
	void reg_fac(char* mod_name, mod_factory* mod_fac);
	void remove_all_fac();
	mod_factory* get_mod_fac(char* mod_name);

	mod_instance* create_mod(char* mod_name);
	void init_mod(char* mod_name);
	void release_mod(char* mod_name);
};

#endif