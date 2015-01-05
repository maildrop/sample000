#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <tchar.h>
#include <Windows.h>
#include <commctrl.h>
#include "verify.h"

#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")

HINSTANCE& getHINSTANCE(){
  static HINSTANCE hInstance(NULL);
  return hInstance;
}

static int entpryPoint( HINSTANCE hInstance , LPCTSTR lpCmdLine, int nCmdShow );

static std::vector<std::basic_string<TCHAR> > tokenize(const std::basic_string<TCHAR>& cmdLine ){
  std::vector< std::basic_string<TCHAR> > tokens;
  auto ite = cmdLine.begin();
  std::basic_string<TCHAR> token{};
  for( ; ite != cmdLine.end() ; ++ite ){
    if( _T('\"') == *ite ){
      // TODO 
    }else if( _T('\'') == *ite ){
      // TODO 
    }else if( _T('\\') == *ite ){
      ++ite;
      if( ite != cmdLine.end() ){
        token.push_back( *ite );
      }
    }else if( _T(' ') == *ite ){
      if(! token.empty() ){
        tokens.push_back( token );
      }
      token.clear();
    }else{
      token.push_back( *ite );
    }
  }
  if( !token.empty()){
    tokens.push_back( token );
  }
  return tokens;
}

static int entpryPoint( HINSTANCE hInstance , LPCTSTR lpCmdLine, int nCmdShow ){
  std::locale::global(std::locale( std::locale::classic(),"",std::locale::ctype ) );
  InitCommonControls();// コモンコントロールの呼び出し
  getHINSTANCE() = hInstance;
  std::vector< std::basic_string<TCHAR> > tokens = tokenize( std::basic_string<TCHAR>( lpCmdLine ) );
  {
    for( auto&& token : tokens ){
      if( token == _T("-debug") ){
        verify_h::implement::isEnable() = true;
      }
      std::wcout << token << std::endl;
    }
  }

  UNREFERENCED_PARAMETER( lpCmdLine );
  UNREFERENCED_PARAMETER( nCmdShow );
  VERIFY( !"why?" );
  return 0;
}

int main(int,char*[]){
  return entpryPoint( ::GetModuleHandle( NULL ), ::GetCommandLine() , SW_SHOW);
}
