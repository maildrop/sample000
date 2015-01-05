
all:
	cd src & make 
clean:
	@if exist *~ for /F "usebackq delims=" %%F in (`dir *~ /B`) do @del %%F 
	cd src & make $@

