
#define Q_NEW_HEAD(Q_HEAD_TYPE, Q_ELEM_TYPE) \
typedef struct Q_HEAD_TYPE { \
    struct Q_ELEM_TYPE *front; \
    struct Q_ELEM_TYPE *end; \
} Q_HEAD_TYPE;

#define Q_NEW_LINK(Q_ELEM_TYPE) \
    struct{ \
        struct Q_ELEM_TYPE *prev; \
        struct Q_ELEM_TYPE *next; \
    }

#define Q_INIT_HEAD(Q_HEAD) \
    do { \
        (Q_HEAD)->front = NULL; \
        (Q_HEAD)->end = NULL; \
    } while (0)

#define Q_INIT_ELEM(Q_ELEM, LINK_NAME) \
    do { \
        (Q_ELEM)->LINK_NAME.prev = NULL; \
        (Q_ELEM)->LINK_NAME.next = NULL; \
    } while (0)

#define Q_INSERT_FRONT(Q_HEAD, Q_ELEM, LINK_NAME)\
    do { \
        (Q_ELEM)->LINK_NAME.next = (Q_HEAD)->front; \
        (Q_ELEM)->LINK_NAME.prev = NULL; \
        if ( (Q_HEAD)->front ) \
            (Q_HEAD)->front->LINK_NAME.prev = Q_ELEM; \
        else \
            (Q_HEAD)->end = Q_ELEM; \
        (Q_HEAD)->front = Q_ELEM; \
    } while (0)

#define Q_INSERT_TAIL(Q_HEAD, Q_ELEM, LINK_NAME) \
    do { \
        (Q_ELEM)->LINK_NAME.prev = (Q_HEAD)->end; \
        (Q_ELEM)->LINK_NAME.next = NULL; \
        if ( (Q_HEAD)->end ) \
            (Q_HEAD)->end->LINK_NAME.next = Q_ELEM; \
        else \
            (Q_HEAD)->front = Q_ELEM; \
        (Q_HEAD)->end = Q_ELEM; \
    } while (0)

#define Q_GET_FRONT(Q_HEAD) (Q_HEAD)->front

#define Q_GET_TAIL(Q_HEAD) (Q_HEAD)->end

#define Q_GET_NEXT(Q_ELEM, LINK_NAME) (Q_ELEM)->LINK_NAME.next

#define Q_GET_PREV(Q_ELEM, LINK_NAME) (Q_ELEM)->LINK_NAME.prev

#define Q_INSERT_AFTER(Q_HEAD,Q_INQ,Q_TOINSERT,LINK_NAME) \
    do { \
        (Q_TOINSERT)->LINK_NAME.next = (Q_INQ)->LINK_NAME.next; \
        (Q_TOINSERT)->LINK_NAME.prev = Q_INQ; \
    if ( (Q_HEAD)->end == Q_INQ ) { \
        (Q_HEAD)->end = Q_TOINSERT; \
    } \
    else { \
        (Q_INQ)->LINK_NAME.next->LINK_NAME.prev = Q_TOINSERT; \
    } \
    (Q_INQ)->LINK_NAME.next = Q_TOINSERT; \
    } while (0)

#define Q_INSERT_BEFORE(Q_HEAD, Q_INQ, Q_TOINSERT, LINK_NAME) \
    do { \
        (Q_TOINSERT)->LINK_NAME.next = (Q_INQ); \
        (Q_TOINSERT)->LINK_NAME.prev = (Q_INQ)->LINK_NAME.prev; \
        if ( (Q_HEAD)->front == (Q_INQ) )	{ \
	        (Q_HEAD)->front = (Q_TOINSERT); \
        } \
        else { \
            (Q_INQ)->LINK_NAME.prev->LINK_NAME.next = (Q_TOINSERT); \
        } \
        (Q_INQ)->LINK_NAME.prev = (Q_TOINSERT); \
    } while (0)

#define Q_REMOVE(Q_HEAD,Q_ELEM,LINK_NAME) \
	do { \
	    if ( (Q_ELEM)->LINK_NAME.prev ) \
            (Q_ELEM)->LINK_NAME.prev->LINK_NAME.next = (Q_ELEM)->LINK_NAME.next; \
	    else \
		    (Q_HEAD)->front = (Q_ELEM)->LINK_NAME.next; \
	    if ( (Q_ELEM)->LINK_NAME.next ) \
		    (Q_ELEM)->LINK_NAME.next->LINK_NAME.prev = (Q_ELEM)->LINK_NAME.prev; \
	    else \
		    (Q_HEAD)->end = (Q_ELEM)->LINK_NAME.prev; \
	    Q_INIT_ELEM(Q_ELEM, LINK_NAME); \
	} while (0)

#define Q_FOREACH(CURRENT_ELEM,Q_HEAD,LINK_NAME) \
    for (CURRENT_ELEM = (Q_HEAD)->front; \
         CURRENT_ELEM != NULL; \
         CURRENT_ELEM = CURRENT_ELEM->LINK_NAME.next) \

