#include "hanlder_manager.h"

#include "handle.h"

void handler_manager::register_handler(handle *_handle)
{
	for (;;)
	{
		int handler = 0;
		for ( int i=0; i<m_numSlots; i++ )
		{
			handler = i+m_handleIdx;
			if ( m_slots[handler] == NULL )
			{
				// Gets an availble position.
				int slotHash = handler&(m_numSlots-1);

				// 
				m_slots[slotHash] = _handle;
				m_slots[slotHash]->m_handle = handler;

				m_handleIdx = handler;

				return handle;
			}
		}

		// Double slot capacity.
		handle** newSlots = malloc(m_numSlots*2*sizeof(handle));
		memset( newSlots, 0, m_numSlots*2*sizeof(handle) );

		for ( int i=0; i<m_numSlots; i++ )
		{
			int slotHash = m_slots[i]->m_handle&(m_numSlots*2-1);
			assert(newSlots[slotHash]==NULL);
			newSlots[slotHash] = m_slots[i];
		}

		// Replaces old slots.
		free(m_slots);
		m_slots = newSlots;
		m_numSLots *= 2;
	}	
}

void handler_mananger::retire_handler(int handle)
{
	int slotHash = handle&(m_numSlots-1);

	handle *pHandle = m_slots[slotHash];
	if ( NULL != pHandle && pHandle->m_handle == handle )
	{
		m_slots[slotHash] = NULL;
	}
}