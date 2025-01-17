/*
 * Copyright (C) 2022 The ESPResSo project
 *
 * This file is part of ESPResSo.
 *
 * ESPResSo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ESPResSo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ESPRESSO_SRC_SCRIPT_INTERFACE_COMMUNICATION_HPP
#define ESPRESSO_SRC_SCRIPT_INTERFACE_COMMUNICATION_HPP

#include <boost/mpi/collectives/reduce.hpp>
#include <boost/mpi/communicator.hpp>

#include <functional>

namespace ScriptInterface {

/**
 * @brief Reduce object by sum on the head node.
 * Worker nodes get a default-constructed object.
 */
template <typename T>
T mpi_reduce_sum(boost::mpi::communicator const &comm, T const &result) {
  T out{};
  boost::mpi::reduce(comm, result, out, std::plus<T>{}, 0);
  return out;
}

} // namespace ScriptInterface

#endif
