#pragma once

/// @brief Ğåáğà äåğåâà.
struct Rib
{
	/// @brief Óêàçàòåëü íà ïğåäûäóùåå ğåáğî.
	Rib* prev;

	/// @brief Ñòğåëêà.
	std::string str;

	/// @brief Ñîçäàåò ıêçåìïëÿğ ñòğóêòóğû Rib.
	/// @param prev Ïğåäûäóùåå ğåáğî.
	/// @param str Ñòğåëêà.
	Rib(Rib* prev, std::string str)
	{
		this->prev = prev;
		this->str = str;
	}
};