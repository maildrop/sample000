#pragma once
#if !defined( VERIFY_H_HEADER_GUARD ) 
#define VERIFY_H_HEADER_GUARD 1

#ifdef __cplusplus
#include <cassert>
namespace verify_h{
  namespace implement{
    inline bool& isEnable(){
      static bool flag(false);
      return flag;
    }
    template<typename type_t>
    inline type_t&& VERIFY_implement( type_t&& arg , const char* msg ){
      if(! arg ){
        if( nullptr != msg ){
          if( isEnable() ){
            ::OutputDebugStringA( msg );
          }
        }
      }
      return std::forward<type_t>(arg);
    }
  };
};
#else /* __cplusplus */
#include <assert.h>
#endif /* __cplusplus */

#if !defined( VERIFY )

#if defined( NDEBUG )
#if defined( __cplusplus  )
#define VERIFY( exp ) (verify_h::implement::VERIFY_implement( exp , #exp ))
#else /* defined( __cplusplus  ) */
#define VERIFY( exp ) ( exp )
#endif /* defined( __cplusplus  ) */

#else /* defined( NDEBUG ) */
#define VERIFY( exp ) assert( exp )
#endif /* defined( NDEBUG ) */

#endif /* !defined( VERIFY ) */

#endif /* VERIFY_H_HEADER_GUARD */


