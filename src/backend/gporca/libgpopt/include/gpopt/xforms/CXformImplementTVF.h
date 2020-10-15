//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2012 EMC Corp.
//
//	@filename:
//		CXformImplementTVF.h
//
//	@doc:
//		Implement logical TVF with a physical TVF
//---------------------------------------------------------------------------
#ifndef GPOPT_CXformImplementTVF_H
#define GPOPT_CXformImplementTVF_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformImplementation.h"

namespace gpopt
{
using namespace gpos;

//---------------------------------------------------------------------------
//	@class:
//		CXformImplementTVF
//
//	@doc:
//		Implement TVF
//
//---------------------------------------------------------------------------
class CXformImplementTVF : public CXformImplementation
{
private:
public:
	CXformImplementTVF(const CXformImplementTVF &) = delete;

	// ctor
	explicit CXformImplementTVF(CMemoryPool *mp);

	// ctor
	explicit CXformImplementTVF(CExpression *pexprPattern);

	// dtor
	virtual ~CXformImplementTVF() = default;

	// ident accessors
	virtual EXformId
	Exfid() const
	{
		return ExfImplementTVF;
	}

	// return a string for xform name
	virtual const CHAR *
	SzId() const
	{
		return "CXformImplementTVF";
	}

	// compute xform promise for a given expression handle
	virtual EXformPromise Exfp(CExpressionHandle &exprhdl) const;

	// actual transform
	void Transform(CXformContext *pxfctxt, CXformResult *pxfres,
				   CExpression *pexpr) const;

};	// class CXformImplementTVF

}  // namespace gpopt

#endif	// !GPOPT_CXformImplementTVF_H

// EOF
