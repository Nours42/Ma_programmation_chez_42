# ft_irc

```
FINAL GRADE: 125/100
```

ft_irc is a group project which, as its name suggests, makes us recreate an IRC server (from scratch, in C++). The server follows the [RFC 2812](https://www.rfc-editor.org/rfc/rfc2812) specification and can therefore be used with existing IRC clients.

The project follows the subject, and also exceeds all the proposed bonuses (even if it does not yet contain all the features available in a real IRC server).

## Usage

### Build and start the server

```bash
make
./ircserv <port> <password>
# ./ircserv 6667 pass123
```

### Build and connect the bot
```bash
cd bot/
make
./ftbot <host> <port> <password>
# ./ftbot localhost 6667 pass123
```

You can talk to the bot by private message, or in the `#bot` channel that it automatically joins.
Available commands are `help`, `ping`, `pong`, `hi`, `dice` and `joke`.

```bash
# Start private message session:
/query ircbot
# Join #bot channel
/join #bot
```

### Connect to the server with a client

With Weechat:
```bash
weechat -t irc://:<password>@<host>:<port>/<channel>
# weechat -t irc://:pass123@localhost:6667/#test
```
