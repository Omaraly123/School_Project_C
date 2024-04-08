/** 
 * File: std_Scope.h
 * Author: Eng- Mohamed Mokhtar
 * Group: Online16
 * Date: 2024,Feb
 * Description: 
 * Version: 1.0
 */

#ifndef __STD_HEADERS_STD_SCOPE_H__ 
#define __STD_HEADERS_STD_SCOPE_H__

/*-------------------------------------------------------------*/
#define STAGLO   static     // static global
#define STALOC   static     // static local
/*-------------------------------------------------------------*/

#define std_VAR(VarType, MemoryClass)        VarType
#define std_STATIC(VarType, MemoryClass)     static VarType
#define std_CONST(VarType, MemoryClass)      const VarType

#define std_GLOBAL
#define std_LOCAL    static

#define std_FUNC(RetType, MemoryClass)       RetType

#endif /* __STD_HEADERS_STD_SCOPE_H__ */
