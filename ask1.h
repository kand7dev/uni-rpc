/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */
/* ΒΙΚΤΩΡ ΡΟΜΑΝΙΟΥΚ 713242017024 ΕΡΓ1 */
#ifndef _ASK1_H_RPCGEN
#define _ASK1_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C"
{
#endif

	struct mo
	{
		struct
		{
			u_int b_len;
			int *b_val;
		} b;
		float m;
	};
	typedef struct mo mo;

	struct min_max
	{
		struct
		{
			u_int b_len;
			int *b_val;
		} b;
		int min;
		int max;
	};
	typedef struct min_max min_max;

	struct ay
	{
		struct
		{
			u_int b_len;
			int *b_val;
		} b;
		struct
		{
			u_int res_len;
			float *res_val;
		} res;
		int a;
	};
	typedef struct ay ay;

#define FIND_M 0x23451111
#define FIND_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define FIND 1
	extern mo *find_1(mo *, CLIENT *);
	extern mo *find_1_svc(mo *, struct svc_req *);
	extern int find_m_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FIND 1
extern mo *find_1();
extern mo *find_1_svc();
extern int find_m_1_freeresult();
#endif /* K&R C */

#define FIND_MIN_MAX 0x23451112
#define MIN_MAX_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define FIND_MN 1
	extern min_max *find_mn_1(min_max *, CLIENT *);
	extern min_max *find_mn_1_svc(min_max *, struct svc_req *);
	extern int find_min_max_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FIND_MN 1
extern min_max *find_mn_1();
extern min_max *find_mn_1_svc();
extern int find_min_max_1_freeresult();
#endif /* K&R C */

#define CALC_AY 0x23451113
#define AY_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define FIND_AY 1
	extern ay *find_ay_1(ay *, CLIENT *);
	extern ay *find_ay_1_svc(ay *, struct svc_req *);
	extern int calc_ay_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FIND_AY 1
extern ay *find_ay_1();
extern ay *find_ay_1_svc();
extern int calc_ay_1_freeresult();
#endif /* K&R C */

	/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
	extern bool_t xdr_mo(XDR *, mo *);
	extern bool_t xdr_min_max(XDR *, min_max *);
	extern bool_t xdr_ay(XDR *, ay *);

#else /* K&R C */
extern bool_t xdr_mo();
extern bool_t xdr_min_max();
extern bool_t xdr_ay();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ASK1_H_RPCGEN */