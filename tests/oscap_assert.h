/*
 * Copyright 2018 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Authors:
 *      Jan Černý <jcerny@redhat.com>
 */


#ifndef OSCAP_ASSERT_H
#define OSCAP_ASSERT_H

/* Assert macro for OpenSCAP tests in C */
/* Unlike standard assert() macro this works even if NDEBUG is defined. */
#define oscap_assert(expr) \
	if (!(expr)) { \
		fprintf(stderr, "Assertion failed: %s, file %s, line %d, function %s.", #expr, __FILE__, __LINE__, __PRETTY_FUNCTION__); \
		abort(); \
	}

#endif /* OSCAP_ASSERT_H */
