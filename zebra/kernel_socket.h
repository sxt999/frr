/*
 * Exported kernel_socket functions, exported only for convenience of
 * sysctl methods.
 *
 * This file is part of Quagga.
 *
 * Quagga is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * Quagga is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; see the file COPYING; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __ZEBRA_KERNEL_SOCKET_H
#define __ZEBRA_KERNEL_SOCKET_H

#ifdef __cplusplus
extern "C" {
#endif

/* Error codes of zebra. */
#define ZEBRA_ERR_NOERROR                0
#define ZEBRA_ERR_RTEXIST               -1
#define ZEBRA_ERR_RTUNREACH             -2
#define ZEBRA_ERR_EPERM                 -3
#define ZEBRA_ERR_RTNOEXIST             -4
#define ZEBRA_ERR_KERNEL                -5

extern void rtm_read(struct rt_msghdr *);
extern int ifam_read(struct ifa_msghdr *);
extern int ifm_read(struct if_msghdr *);
extern int rtm_write(int, union sockunion *, union sockunion *,
		     union sockunion *, union sockunion *, unsigned int,
		     enum blackhole_type, int);
#ifdef __FreeBSD__
extern void build_freebsd_bridge_membership(void);
extern int ksocket_macfdb_read(struct zebra_ns *);
extern int ksocket_macfdb_read_for_bridge(struct zebra_ns *, struct interface *, struct interface *);
extern int ksocket_macfdb_read_specific_mac(struct zebra_ns *, struct interface *, const struct ethaddr *, vlanid_t);
#endif
extern const struct message rtm_type_str[];

#ifdef __cplusplus
}
#endif

#endif /* __ZEBRA_KERNEL_SOCKET_H */
