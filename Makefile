
all:

clean:
	@if exist *~ for /F "usebackq delims=" %%F in (`dir *~ /B`) do @del %%F 
