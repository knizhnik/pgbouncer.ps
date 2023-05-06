#include "common/uthash.h"

#define PS_IGNORE 0
#define PS_HANDLE 1

typedef struct PgParsedPreparedStatement
{
  const char    *name;
  PgParsePacket *pkt;
  UT_hash_handle hh;
} PgParsedPreparedStatement;

typedef struct PgServerPreparedStatement
{
  char *name;
  char *query;
  uint64_t bind_count;
  UT_hash_handle hh;
} PgServerPreparedStatement;

bool handle_parse_command(PgSocket *client, PktHdr *pkt);
bool handle_bind_command(PgSocket *client, PktHdr *pkt);
bool handle_describe_command(PgSocket *client, PktHdr *pkt);
bool handle_close_statement_command(PgSocket *client, PktHdr *pkt, PgClosePacket *close_packet);

void ps_client_free(PgSocket *client);
void ps_server_free(PgSocket *server);
