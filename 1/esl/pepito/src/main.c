/*
** Epitech Security Lab
** http://esl.epitech.net - <staff@esl.epitech.eu>
**
** Zerk wrote this.
** As long as you retain this notice you can do whatever
** you want with this stuff. If we meet some day, and you
** think this stuff is worth it, you can buy me a Chimay
** blue in return.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pepito.h"

#include "daemon.h"
#include "network.h"
#include "utils.h"

static char	       	guestBook[512] = "##################################";
static char		password[512] = "";

/* Password check ----------------------------------------------- */

int			passwordCheck(char *sentPassword)
{
  int			res;

  if (sentPassword == NULL)
    return (-1);
  if (strlen(password)) {
    if ((res = strcmp(sentPassword, password)) != 0)
      sendLogMessage(PASSWD_FAIL);
    return (res);
  }
  return (0);
}

/* Packet handlers ---------------------------------------------- */

int			handlerChangePassword(void *packetPtr, size_t packetSize)
{
  char			*newPasswd;
  char			*oldPasswd;

  newPasswd = getStr(&packetPtr, &packetSize);
  oldPasswd = getStr(&packetPtr, &packetSize);
  if (passwordCheck(oldPasswd))
    return (1);
  if (newPasswd) {
    if (strlen(newPasswd) >= sizeof(password)) {
      sendLogMessage(PASSWD_TOO_LONG);
      return (1);
    }
    strcpy(password, newPasswd);
    sendLogMessage(PASSWD_CHANGE);
    free(newPasswd);
  }
  free(oldPasswd);
  return (0);
}

int			handlerAddToGuestBook(void *packetPtr, size_t packetSize)
{
  char			*msg;

  if ((msg = getStr(&packetPtr, &packetSize))) {
    strncpy(guestBook, msg, sizeof(guestBook) - 1);
    sendLogMessage(AD_CHANGE);
    free(msg);
  }
  return (0);
}

int			updateBuf(char buf[512], void *packetPtr, size_t packetSize)
{
  char			*name = NULL;

  if ((name = getStr(&packetPtr, &packetSize))) {
    if (snprintf(buf, sizeof(buf) - 1, "touch lastvisit_%s\n", name) >= 512)
      return (1);
    free(name);
    return (0);
  }
  return (1);
}

int		handlerUpdateLastVisit(void *packetPtr, size_t packetSize)
{
  char                  buf[512] = {0};
  int                   pid;

  if (!updateBuf(buf, packetPtr, packetSize))
  {
    pid = fork();
    if (pid == 0)
    {
      execlp("touch", "touch", buf + 6, NULL);
      exit (EXIT_FAILURE);
    }
  }
  return (0);
}

int			handlerShowGuestBook(void *packetPtr, size_t packetSize)
{
  char			*passwd;
  char			buf[512] = {0};

  passwd = getStr(&packetPtr, &packetSize);
  if (strlen(guestBook) < 512 - 20) {
    snprintf(buf, sizeof(buf) - 1, "Dernier message : %s", guestBook);
    if (passwordCheck(passwd))
      return (1);
  }
  write(1, buf, strlen(buf));
  return (0);
}

static int		(*handlerTab[])(void *packetPtr, size_t packetSize) =
{
  handlerChangePassword,
  handlerAddToGuestBook,
  handlerShowGuestBook,
  handlerUpdateLastVisit,
  NULL
};
#define HANDLER_LEN (sizeof(handlerTab) / sizeof (handlerTab[0]))

/* handlePacket() */

int			handlePacket(void *packetPtr, size_t packetSize)
{
  int			cmdId;

  cmdId = getNumber(&packetPtr, &packetSize);
  if (cmdId >= (int)HANDLER_LEN - 1 || cmdId < 0)
    fprintf(stderr, "ID (%i) out of range.\n", cmdId);
  else
    handlerTab[cmdId](packetPtr, packetSize);
  return (0);
}

/* main */

int			main(int argc, char **argv)
{
  if (argc > 1) {
    if (!strcmp(argv[1], "start"))
      return (runDaemon(0));
    else if (!strcmp(argv[1], "debug"))
      return (runDaemon(1));
    else if (!strcmp(argv[1], "stop"))
      return (stopDaemon());
  }
  fprintf(stderr, "usage: %s {start|debug|stop}\n", argv[0]);
  return (EXIT_SUCCESS);
}
