/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPCCHAT_H_RPCGEN
#define _RPCCHAT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct message {
	char *operator;
	char *message;
	long timestamp;
};
typedef struct message message;

struct historic {
	struct {
		u_int list_len;
		message *list_val;
	} list;
	int size;
};
typedef struct historic historic;

#define rpcchat 0x20000001
#define CHATMESSAGING 1

#if defined(__STDC__) || defined(__cplusplus)
#define writechat 1
extern  void * writechat_1(message *, CLIENT *);
extern  void * writechat_1_svc(message *, struct svc_req *);
#define getChat 2
extern  historic * getchat_1(long *, CLIENT *);
extern  historic * getchat_1_svc(long *, struct svc_req *);
extern int rpcchat_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define writechat 1
extern  void * writechat_1();
extern  void * writechat_1_svc();
#define getChat 2
extern  historic * getchat_1();
extern  historic * getchat_1_svc();
extern int rpcchat_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_message (XDR *, message*);
extern  bool_t xdr_historic (XDR *, historic*);

#else /* K&R C */
extern bool_t xdr_message ();
extern bool_t xdr_historic ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPCCHAT_H_RPCGEN */
