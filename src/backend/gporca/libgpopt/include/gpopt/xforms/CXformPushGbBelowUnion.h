//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2013 Pivotal, Inc.
//
//	@filename:
//		CXformPushGbBelowUnion.h
//
//	@doc:
//		Push grouping below Union operation
//---------------------------------------------------------------------------
#ifndef GPOPT_CXformPushGbBelowUnion_H
#define GPOPT_CXformPushGbBelowUnion_H

#include "gpos/base.h"

#include "gpopt/operators/CLogicalUnion.h"
#include "gpopt/xforms/CXformPushGbBelowSetOp.h"

namespace gpopt
{
using namespace gpos;

//---------------------------------------------------------------------------
//	@class:
//		CXformPushGbBelowUnion
//
//	@doc:
//		Push grouping below Union operation
//
//---------------------------------------------------------------------------
class CXformPushGbBelowUnion : public CXformPushGbBelowSetOp<CLogicalUnion>
{
private:
public:
	CXformPushGbBelowUnion(const CXformPushGbBelowUnion &) = delete;

	// ctor
	explicit CXformPushGbBelowUnion(CMemoryPool *mp)
		: CXformPushGbBelowSetOp<CLogicalUnion>(mp)
	{
	}

	// dtor
	virtual ~CXformPushGbBelowUnion() = default;

	// Compatibility function
	virtual BOOL
	FCompatible(CXform::EXformId exfid)
	{
		return ExfPushGbBelowUnion != exfid;
	}

	// ident accessors
	virtual EXformId
	Exfid() const
	{
		return ExfPushGbBelowUnion;
	}

	virtual const CHAR *
	SzId() const
	{
		return "CXformPushGbBelowUnion";
	}

};	// class CXformPushGbBelowUnion

}  // namespace gpopt

#endif	// !GPOPT_CXformPushGbBelowUnion_H

// EOF
