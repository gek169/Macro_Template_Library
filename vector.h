#include <stdlib.h>
#include <stdio.h>


#define VECDECL(name, basetype)	\
	typedef struct{				\
		size_t count;			\
		size_t allocated;		\
		basetype* members;		\
	}name;			\
	/*create a vector*/			\
	static name create_##name(){\
		name retval;\
		retval.count = 0;		\
		retval.allocated = 0;	\
		retval.members = NULL;	\
		return retval;			\
	}							\
	static void name##_reserve(\
		name *me,		\
		size_t sz						\
	){									\
		if(me->allocated >= sz) return;\
		if(me->allocated < sz)			\
		me->members = realloc(me->members, sz * sizeof(basetype));\
		if(me->members == NULL){puts("Failed Malloc");exit(1);}\
		me->allocated = sz;					\
		/*puts("<Allocation>");*/			\
	}										\
	static size_t name##_push(				\
		name *me,							\
		basetype q							\
	){										\
		me->count++;						\
		if(me->allocated < me->count)name##_reserve(me,me->count); 	\
		me->members[me->count - 1] = q;		\
	}										\
	static basetype name##_pop(				\
		name *me							\
	){										\
		if(me->count == 0)					\
			{puts("ERROR: Cannot pop empty vector.");exit(1);}\
		me->count--;						\
		return me->members[me->count];		\
	}										\
	static void name##_destroy(name *me){	\
		if(me->members) free(me->members);	\
		me->members = 0;					\
		me->allocated = 0;					\
		me->count = 0;						\
	}										\


