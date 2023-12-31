#include "monty.h"

/**
  * _free_object - free object.
  * @object: object to free.
  * @stack: stack_t object.
  */
void _free_object(stack_t *stack, obj_t *object)
{
	int i;

	if (object)
	{
		if (object->str)
			free(object->str);
		if (object->flag != NOERR)
		{
			if (object->str_tokenized)
			{
				i = 0;
				while ((object->str_tokenized)[i])
				{
					free((object->str_tokenized)[i]);
					i++;
				}
				free(object->str_tokenized);
			}
		}
		if (stack)
		{
			_free_stack(stack);
		}
		free(object);
	}
}
