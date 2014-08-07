#include "message_queue.h"

#define DEFAULT_QUEUE_SIZE 64

message_queue::message_queue()
	: m_head(0), m_tail(0), m_capactiy(DEFAULT_QUEUE_SIZE)
{
	msg_entities = malloc(sizeof(struct message_entity) * m_capacity);
}

void message_queue::release()
{
	free(msg_entities);
}

void message_queue::_expand_queue()
{
	struct message_entity* newq = malloc(sizeof(struct message_entity) * m_capacity* 2);
		
	for (int i=0; i<m_capacity; i++)
	{
		newq[i] = msg_enities[(m_head+i) % m_capacity];
	}

	m_head = 0;
	m_tail = m_capacity;
	m_capacity *= 2;

	free(msg_entities);
	msg_entities = newq;
}

void message_queue::push(message_entity* entity)
{
	msg_entities[m_tail] = entity;
	m_tail++;
	if (m_tail >= m_capactiy)
	{
		_expand_queue();
	}
}

int message_queue::pop(message_entity *out_msg)
{
	int result = 0;
	if (m_head != m_tail){
		*out_msg = msg_entities[m_head];
		
		result = 1;

		if (m_head >= m_capactiy){
			m_head = 0;
		}
	}

	return result;
}

void message_queue::lock()
{
}

void message_queue::unlock()
{
}


