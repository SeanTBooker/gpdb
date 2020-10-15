//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2011 Greenplum, Inc.
//
//	@filename:
//		CParseHandlerScalarNullTest.h
//
//	@doc:
//
//		SAX parse handler class for parsing scalar NullTest.
//---------------------------------------------------------------------------

#ifndef GPDXL_CParseHandlerScalarNullTest_H
#define GPDXL_CParseHandlerScalarNullTest_H

#include "gpos/base.h"
#include "naucrates/dxl/parser/CParseHandlerScalarOp.h"

#include "naucrates/dxl/operators/CDXLScalarNullTest.h"


namespace gpdxl
{
using namespace gpos;

XERCES_CPP_NAMESPACE_USE

//---------------------------------------------------------------------------
//	@class:
//		CParseHandlerScalarNullTest
//
//	@doc:
//		Parse handler for parsing a scalar op expression
//
//---------------------------------------------------------------------------
class CParseHandlerScalarNullTest : public CParseHandlerScalarOp
{
private:
	// process the start of an element
	void StartElement(
		const XMLCh *const element_uri,			// URI of element's namespace
		const XMLCh *const element_local_name,	// local part of element's name
		const XMLCh *const element_qname,		// element's qname
		const Attributes &attr					// element's attributes
	);

	// process the end of an element
	void EndElement(
		const XMLCh *const element_uri,			// URI of element's namespace
		const XMLCh *const element_local_name,	// local part of element's name
		const XMLCh *const element_qname		// element's qname
	);

public:
	CParseHandlerScalarNullTest(const CParseHandlerScalarNullTest &) = delete;

	// ctor
	CParseHandlerScalarNullTest(CMemoryPool *mp,
								CParseHandlerManager *parse_handler_mgr,
								CParseHandlerBase *parse_handler_root);
};

}  // namespace gpdxl
#endif	// GPDXL_CParseHandlerScalarNullTest_H

//EOF
