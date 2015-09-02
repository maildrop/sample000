/**

 */
#include <iostream>
#include <tuple>
#include <locale>
#include "verify.h"

template<typename type_t>
struct Range_t: public std::tuple<type_t * const, type_t * const>{
  inline Range_t( type_t* const _begin ,const size_t size ) :
    std::tuple<type_t* const, type_t* const>( _begin , std::next( _begin, size ) ){}

  inline Range_t( type_t* const _begin ,const type_t* _end) :
    std::tuple<type_t* const, type_t* const>( _begin , _end ){}

  inline type_t * const begin() const { return std::get<0>( *this ); }
  inline type_t * const end()   const { return std::get<1>( *this ); }
};

template<typename type_t>
Range_t<type_t> Range(type_t* &argv, size_t size ){
  return Range_t<type_t>( argv , size );
}

int main(int,char*[]);

int main(int argc,char* argv[])
{
#if !( defined( __MINGW32__ ) || defined( __MINGW64__ ) )
  std::locale::global( std::locale("") ); 
#else
  std::locale::global( std::locale("C") );
#endif
  
  std::cout << argc << std::endl;
  auto l = Range( argv , argc );
  UNREFERENCED_PARAMETER( l );
  
  Range_t<const char*> ll( const_cast<const char**>(argv) , argc );
  for( auto&& l : ll ){
    //std::cout << static_cast<const void*>( l ) << std::endl;
    std::cout << l << std::endl;
  }
  return EXIT_SUCCESS;
}
