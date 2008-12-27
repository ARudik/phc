#ifndef _MICG_TRANSFORM_H_
#define _MICG_TRANSFORM_H_

#include <iostream>
#include <sstream>
#include <iomanip>
#include "boost/lexical_cast.hpp"
#include "lib/error.h"
#include "lib/Object.h"
#include "lib/List.h"
#include "lib/String.h"
#include "lib/Boolean.h"
#include "lib/Integer.h"
#include <list>
#include <string>
#include <cstring>
#include <cassert>


#include "MICG.h"

namespace MICG{
class Transform
{
public:
    virtual ~Transform();
/* Invoked before the children are transformed */
public:
    virtual Template* pre_template(Template* in);
    virtual Signature* pre_signature(Signature* in);
    virtual void pre_formal_parameter(Formal_parameter* in, Formal_parameter_list* out);
    virtual void pre_rule(Rule* in, Rule_list* out);
    virtual Lookup* pre_lookup(Lookup* in);
    virtual Expr* pre_equals(Equals* in);
    virtual Body* pre_body(Body* in);
    virtual void pre_macro_call(Macro_call* in, Body_part_list* out);
    virtual PATTERN_NAME* pre_pattern_name(PATTERN_NAME* in);
    virtual TYPE* pre_type(TYPE* in);
    virtual ATTR_NAME* pre_attr_name(ATTR_NAME* in);
    virtual PARAM_NAME* pre_param_name(PARAM_NAME* in);
    virtual STRING* pre_string(STRING* in);
    virtual void pre_c_code(C_CODE* in, Body_part_list* out);
/* Invoked after the children have been transformed */
public:
    virtual Template* post_template(Template* in);
    virtual Signature* post_signature(Signature* in);
    virtual void post_formal_parameter(Formal_parameter* in, Formal_parameter_list* out);
    virtual void post_rule(Rule* in, Rule_list* out);
    virtual Lookup* post_lookup(Lookup* in);
    virtual Expr* post_equals(Equals* in);
    virtual Body* post_body(Body* in);
    virtual void post_macro_call(Macro_call* in, Body_part_list* out);
    virtual PATTERN_NAME* post_pattern_name(PATTERN_NAME* in);
    virtual TYPE* post_type(TYPE* in);
    virtual ATTR_NAME* post_attr_name(ATTR_NAME* in);
    virtual PARAM_NAME* post_param_name(PARAM_NAME* in);
    virtual STRING* post_string(STRING* in);
    virtual void post_c_code(C_CODE* in, Body_part_list* out);
/* Transform the children of the node */
public:
    virtual void children_template(Template* in);
    virtual void children_signature(Signature* in);
    virtual void children_formal_parameter(Formal_parameter* in);
    virtual void children_rule(Rule* in);
    virtual void children_lookup(Lookup* in);
    virtual void children_equals(Equals* in);
    virtual void children_body(Body* in);
    virtual void children_macro_call(Macro_call* in);
/* Tokens don't have children, so these methods do nothing by default */
public:
    virtual void children_pattern_name(PATTERN_NAME* in);
    virtual void children_type(TYPE* in);
    virtual void children_attr_name(ATTR_NAME* in);
    virtual void children_param_name(PARAM_NAME* in);
    virtual void children_string(STRING* in);
    virtual void children_c_code(C_CODE* in);
/* Call the pre-transform, transform-children post-transform methods in order */
/* Do not override unless you know what you are doing */
public:
    virtual Signature* transform_signature(Signature* in);
    virtual Rule_list* transform_rule_list(Rule_list* in);
    virtual Rule_list* transform_rule(Rule* in);
    virtual Body* transform_body(Body* in);
    virtual PATTERN_NAME* transform_pattern_name(PATTERN_NAME* in);
    virtual Formal_parameter_list* transform_formal_parameter_list(Formal_parameter_list* in);
    virtual Formal_parameter_list* transform_formal_parameter(Formal_parameter* in);
    virtual TYPE* transform_type(TYPE* in);
    virtual PARAM_NAME* transform_param_name(PARAM_NAME* in);
    virtual Expr* transform_expr(Expr* in);
    virtual ATTR_NAME* transform_attr_name(ATTR_NAME* in);
    virtual Body_part_list* transform_body_part_list(Body_part_list* in);
    virtual Body_part_list* transform_body_part(Body_part* in);
    virtual Actual_parameter_list* transform_actual_parameter_list(Actual_parameter_list* in);
    virtual Actual_parameter_list* transform_actual_parameter(Actual_parameter* in);
    virtual Template* transform_template(Template* in);
/* Invoke the right pre-transform (manual dispatching) */
/* Do not override unless you know what you are doing */
public:
    virtual Expr* pre_expr(Expr* in);
    virtual void pre_body_part(Body_part* in, Body_part_list* out);
    virtual void pre_actual_parameter(Actual_parameter* in, Actual_parameter_list* out);
/* Invoke the right post-transform (manual dispatching) */
/* Do not override unless you know what you are doing */
public:
    virtual Expr* post_expr(Expr* in);
    virtual void post_body_part(Body_part* in, Body_part_list* out);
    virtual void post_actual_parameter(Actual_parameter* in, Actual_parameter_list* out);
/* Invoke the right transform-children (manual dispatching) */
/* Do not override unless you what you are doing */
public:
    virtual void children_expr(Expr* in);
    virtual void children_body_part(Body_part* in);
    virtual void children_actual_parameter(Actual_parameter* in);
};
}


#endif
