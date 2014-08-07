#ifndef __HANDLER_MANAGER_INCLUDE_H_
#define __HANDLER_MANAGER_INCLUDE_H_

class handler_manager
{
	public:
		void register_handler(class handle *_handle);
		void retire_handler(int handle);

		void find_by_name();

		void release();

	private:
		int m_handleIdx;

		int m_numSlots;
		class handle **m_slots;
};

#endif
