divert(-1)
#
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988, 1993
#	The Regents of the University of California.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#	This product includes software developed by the University of
#	California, Berkeley and its contributors.
# 4. Neither the name of the University nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

#
#  This is a generic configuration file for FreeBSD 5.X and later systems.
#  If you want to customize it, copy it to a name appropriate for your
#  environment and do the modifications there.
#
#  The best documentation for this .mc file is:
#  /usr/share/sendmail/cf/README or
#  /usr/src/contrib/sendmail/cf/README
#

divert(0)
VERSIONID(`$FreeBSD: src/etc/sendmail/freebsd.mc,v 1.37.2.1.2.1 2009/10/25 01:10:29 kensmith Exp $')
OSTYPE(freebsd6)
DOMAIN(generic)

FEATURE(access_db, `hash -o -T<TMPF> /etc/mail/access')
FEATURE(local_lmtp)
FEATURE(mailertable, `hash -o /etc/mail/mailertable')
FEATURE(virtusertable, `hash -o /etc/mail/virtusertable')
FEATURE(`authinfo')
dnl FEATURE(`accept_unresolvable_domains')

dnl Uncomment to allow relaying based on your MX records.
dnl NOTE: This can allow sites to use your server as a backup MX without
dnl       your permission.
dnl FEATURE(relay_based_on_MX)

dnl DNS based black hole lists
dnl --------------------------------
dnl DNS based black hole lists come and go on a regular basis
dnl so this file will not serve as a database of the available servers.
dnl For that, visit
dnl http://www.google.com/Top/Computers/Internet/E-mail/Spam/Blacklists/

dnl Uncomment to activate Realtime Blackhole List
dnl information available at http://www.mail-abuse.com/
dnl NOTE: This is a subscription service as of July 31, 2001
dnl Alternatively, you can provide your own server and rejection message:
dnl FEATURE(`enhdnsbl', `bl.spamcop.net', `"Spam blocked see: http://spamcop.net/bl.shtml?"$&{client_addr}', `t')

dnl Uncomment the first line to change the location of the default
define(`confDOMAIN_NAME', `mailserver2.k1.com.br')
define(`confMAX_DAEMON_CHILDREN',60)
define(`confDONT_PROBE_INTERFACES',`yes')
define(`confCW_FILE', `-o /etc/mail/local-host-names')


define(`confTO_QUEUERETURN',`8d')
define(`confTO_IDENT', `0s')
define(`confBIND_OPTS', `WorkAroundBrokenAAAA')
define(`confNO_RCPT_ACTION', `add-to-undisclosed')
define(`confPRIVACY_FLAGS', `authwarnings,noexpn,novrfy')


dnl ================SSL/TLS Options======================
dnl ############SMTPAUTH
define(`confAUTH_MECHANISMS', `LOGIN PLAIN DIGEST-MD5')
TRUST_AUTH_MECH(`LOGIN PLAIN DIGEST-MD5')

dnl ############STARTTLS
define(`confCACERT_PATH',`/etc/mail/certs')
define(`SSLCERT',`/etc/mail/certs/servercert.pem')
define(`SSLKEY',`/etc/mail/certs/serverkey.pem')
define(`confCACERT',`/etc/ssl/cacert.pem')
define(`confSERVER_CERT',`SSLCERT')
define(`confCLIENT_CERT',`confSERVER_CERT')
define(`confSERVER_KEY',`SSLKEY')
define(`confCLIENT_KEY',`confSERVER_KEY')
define(`confTLS_SRV_OPTIONS',`V')

dnl ###########SEND OPTIONS
dnl define(`SMART_HOST',`[outbound.mailhop.org]')dnl
dnl define(`RELAY_MAILER_ARGS', `TCP $h 587')dnl
dnl define(`ESMTP_MAILER_ARGS', `TCP $h 587')dnl
DAEMON_OPTIONS(`Port=smtp, Name=IPv4, Family=inet')
DAEMON_OPTIONS(`Port=smtps, Name=TLSMTA, M=s')


dnl #####################SPAM CONTROL...
dnl INPUT_MAIL_FILTER(`bogom',`S=unix:/var/spool/bogofilter/milter.sock, T=S:30s;R:1m')


dnl #####################MAILER PATH
define(`CYRUS_MAILER_PATH',`/usr/pkg/cyrus/bin/deliver')

MAILER(local)
MAILER(smtp)
MAILER(cyrus)
