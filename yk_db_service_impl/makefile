
PROJECT_ROOT := ../../
VPATH	:=./
CPPS	:=$(foreach dir, $(VPATH), $(wildcard $(dir)/*.cpp) )
OBJS	:=$(patsubst %.cpp, %.o, $(CPPS))
DEPS	:=$(patsubst %.cpp, %.d, $(CPPS))

CXX	:=g++
CPPLAGS	:= -g -O0 -std=c++11
INCLUDE	:= -I$(PROJECT_ROOT)/src/yk_db_service_impl -I$(PROJECT_ROOT)/src 
LIBS	:= -pthread -lmysqlclient_r -lmysqlcppconn

RULE	:=all release debugs
TARGET	:=libykdbservice.a

CONFIG	:=debug

OUTDIR_ROOT	:=$(PROJECT_ROOT)/build

OUTDIR	:=$(OUTDIR_ROOT)/$(CONFIG)

FIXEDTARGET	:=$(addprefix $(OUTDIR_ROOT)/lib/, $(TARGET))
FIXEDOBJS	:=$(addprefix $(OUTDIR)/, $(OBJS))
FIXEDDEPS	:=$(addprefix $(OUTDIR)/, $(DEPS))

$(RULE):$(FIXEDOBJS)
	@echo 'Building target: $@'
	ar -r $(FIXEDTARGET) $(FIXEDOBJS)
	@echo 'Finished building target: $@'
	@echo ' '

-include $(FIXEDDEPS)

$(OUTDIR)/%.o:%.cpp
	@echo "Start building $@"
	$(CXX) $(CPPLAGS) $(INCLUDE) -o $@ -c $< -MMD -MF"$(@:%.o=%.d)"
	@echo "Finished building $@"
	@echo " "

clean:
	rm -f $(FIXEDOBJS)
	rm -f $(FIXEDDEPS)
	rm -f $(FIXEDTARGET)
	@echo " "

rebuild:clean all

.PHONY:clean rebuild