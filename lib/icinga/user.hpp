/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2018 Icinga Development Team (https://icinga.com/)      *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef USER_H
#define USER_H

#include "icinga/i2-icinga.hpp"
#include "icinga/user-ti.hpp"
#include "icinga/timeperiod.hpp"
#include "remote/messageorigin.hpp"

namespace icinga
{

/**
 * A User.
 *
 * @ingroup icinga
 */
class User final : public ObjectImpl<User>
{
public:
	DECLARE_OBJECT(User);
	DECLARE_OBJECTNAME(User);

	void AddGroup(const String& name);

	/* Notifications */
	TimePeriod::Ptr GetPeriod() const;

	void ValidateStates(const Lazy<Array::Ptr>& lvalue, const ValidationUtils& utils) override;
	void ValidateTypes(const Lazy<Array::Ptr>& lvalue, const ValidationUtils& utils) override;

protected:
	void Stop(bool runtimeRemoved) override;

	void OnConfigLoaded() override;
	void OnAllConfigLoaded() override;
private:
	mutable boost::mutex m_UserMutex;
};

}

#endif /* USER_H */
