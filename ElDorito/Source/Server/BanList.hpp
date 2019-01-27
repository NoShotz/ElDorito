#pragma once

#include <string>
#include <unordered_set>
#include <cstdint>
#include <istream>
#include <map>
#include "../Utils/Utils.hpp"

namespace Server
{


	/*
	* - Temporary Ban List
	*
	* - This is a temporary ban list that ban players for a specified amount of games.
	* - The amound of games is configurable via server variable.
	*/
	class TempBanList : public Utils::Singleton<TempBanList>
	{
	public:
		TempBanList() { }
		// Adds an IP address to the ban list.
		void AddIp(const std::string ip);
		// Returns whether an IP address is in the ban list.
		inline bool ContainsIp(std::string ip)
		{
			return ipAddresses.find(ip) != ipAddresses.end();
		}
		inline bool RemoveIp(const std::string &ip)
		{
			return ipAddresses.erase(ip) == 1;
		}
		void decrementDuration();
		// Clears ban list. Returns true if successful.
		inline void ClearList()
		{
			ipAddresses.clear();
		}
	private:
		std::map<std::string, int> ipAddresses = std::map<std::string, int>{};
	};


	class HalostatsBanList : public Utils::Singleton<HalostatsBanList>
	{
	public:
		HalostatsBanList() { }
		// Adds an IP address to the ban list.
		inline void AddIp(const std::string ip)
		{
			ipAddresses.insert(ip);
		}
		inline void AddSubnet(const std::string ip)
		{
			subnets.insert(ip);
		}
		inline void AddName(const std::string name)
		{
			names.insert(name);
		}
		inline void AddUID(const std::string uid)
		{
			uids.insert(uid);
		}
		// Returns whether an IP address is in the ban list.
		inline bool ContainsIp(std::string ip)
		{
			return ipAddresses.find(ip) != ipAddresses.end();
		}
		inline bool ContainsSubnet(std::string ip)
		{
			for (std::string subnet : subnets) {
				if (ip.find(subnet) != std::string::npos)
					return true;
			}
			return false;
		}
		inline bool ContainsName(std::string name)
		{
			return names.find(name) != names.end();
		}
		inline bool ContainsUID(std::string uid)
		{
			return uids.find(uid) != uids.end();
		}
		inline bool RemoveIp(const std::string &ip)
		{
			return ipAddresses.erase(ip) == 1;
		}
		// Clears ban list. Returns true if successful.
		inline void ClearList()
		{
			subnets.clear();
			ipAddresses.clear();
			uids.clear();
			names.clear();
		}
	private:
		std::unordered_set<std::string> subnets = std::unordered_set<std::string>{};
		std::unordered_set<std::string> ipAddresses = std::unordered_set<std::string>{};
		std::unordered_set<std::string> uids = std::unordered_set<std::string>{};
		std::unordered_set<std::string> names = std::unordered_set<std::string>{};

	};


	class BanList
	{
	public:
		BanList() { }

		// Constructs a ban list from a stream.
		explicit BanList(std::istream &stream)
		{
			Read(stream);
		}

		// Constructs a ban list from a file.
		explicit BanList(const std::string &path);

		// Adds an IP address to the ban list.
		inline void AddIp(const std::string &ip)
		{
			ipAddresses.insert(ip);
		}
		// Adds an IP address to the ban list.
		inline void AddName(const std::string &name)
		{
			names.insert(name);
		}
		// Returns whether an IP address is in the ban list.
		inline bool ContainsIp(const std::string &ip) const
		{
			return ipAddresses.find(ip) != ipAddresses.end();
		}

		// Removes an IP address from the ban list. Returns true if successful.
		inline bool RemoveIp(const std::string &ip)
		{
			return ipAddresses.erase(ip) == 1;
		}

		// Adds a UID to the ban list.
		inline void AddUid(std::string uid)
		{
			uids.insert(uid);
		}

		// Returns whether a UID is in the ban list.
		inline bool ContainsName(std::string name)
		{
			return names.find(name) != names.end();
		}
		// Returns whether a UID is in the ban list.
		inline bool ContainsUid(std::string uid)
		{
			return uids.find(uid) != uids.end();
		}

		// Removes a UID from the ban list. Returns true if successful.
		inline bool RemoveUid(std::string uid)
		{
			return uids.erase(uid) == 1;
		}

		// Writes the ban list to a stream.
		void Save(std::ostream &stream) const;

		// Writes the ban list to a file.
		void Save(const std::string &path) const;

	private:
		void Read(std::istream &stream);
		std::unordered_set<std::string> names;
		std::unordered_set<std::string> ipAddresses;
		std::unordered_set<std::string> uids;
	};

	const std::string DefaultBanListPath = "mods/server/banlist.txt";

	// Loads the default ban list file.
	// If it does not exist, an empty ban list will be returned.
	BanList LoadDefaultBanList();

	// Saves the default ban list file.
	void SaveDefaultBanList(const BanList &list);
}