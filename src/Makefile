CPP = cl.exe
CPPFLAGS = /D "NDEBUG" /MD /EHsc /Zi /W4 /WX /RTC1 /GS /sdl /D "_UNICODE" /D "UNICODE" /D "WIN32" /D "_WINDOWS" /D "NOMINMAX"
all_TARGET = Hello.exe
Hello_OBJS = Hello.obj

.obj.exe:
	$(CPP) /nologo $(CPPFLAGS) /Fe:$@ $** 
.cpp.obj:
	$(CPP) /nologo $(CPPFLAGS) /Fo:$@ $*.cpp

all: $(all_TARGET)

Hello.exe: $(Hello_OBJS)

Hello.obj: Hello.cpp verify.h

clean:
	for %%F in ( $(all_TARGET) $(Hello_OBJS) *.pdb *.ilk ) do @if exist %%F del %%F
	@if exist *~ for /F "usebackq delims=" %%F in (`dir *~ /B`) do @del %%F 
