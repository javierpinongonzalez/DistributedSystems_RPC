
# This is a template Makefile generated by rpcgen

# Parameters

CLIENT = rpcchat_client
SERVER = rpcchat_server

SOURCES_CLNT.c =
SOURCES_CLNT.h =
SOURCES_SVC.c = 
SOURCES_SVC.h = server.h
SOURCES.x = rpcchat.x

TARGETS_SVC.c = rpcchat_svc.c rpcchat_server.c rpcchat_xdr.c 
TARGETS_CLNT.c = rpcchat_clnt.c rpcchat_client.c rpcchat_xdr.c 
TARGETS = rpcchat.h rpcchat_xdr.c rpcchat_clnt.c rpcchat_svc.c rpcchat_client.c rpcchat_server.c

OBJECTS_CLNT = $(SOURCES_CLNT.c:%.c=%.o) $(TARGETS_CLNT.c:%.c=%.o)
OBJECTS_SVC = $(SOURCES_SVC.c:%.c=%.o) $(TARGETS_SVC.c:%.c=%.o)
# Compiler flags 

CFLAGS += -g -Wall -Wextra
LDLIBS += -lnsl -lpthread
RPCGENFLAGS = 

# Targets 

all : $(CLIENT) $(SERVER)

$(TARGETS) : $(SOURCES.x) 
	rpcgen $(RPCGENFLAGS) $(SOURCES.x)

$(OBJECTS_CLNT) : $(SOURCES_CLNT.c) $(SOURCES_CLNT.h) $(TARGETS_CLNT.c) 

$(OBJECTS_SVC) : $(SOURCES_SVC.c) $(TARGETS_SVC.c) 

$(CLIENT) : $(OBJECTS_CLNT) 
	$(LINK.c) -o $(CLIENT) $(OBJECTS_CLNT) $(LDLIBS) 

$(SERVER) : $(OBJECTS_SVC) 
	$(LINK.c) -o $(SERVER) $(OBJECTS_SVC) $(LDLIBS)

 clean:
	 $(RM) core $(TARGETS) $(OBJECTS_CLNT) $(OBJECTS_SVC) $(CLIENT) $(SERVER)