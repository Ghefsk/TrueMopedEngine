#include <SFML\Graphics.hpp>
#include "../Component/Component.h"
#include <string>

#pragma once



class Spells {
public:
	void SetName(const std::string& name);
	void SetElementType(const std::string& name);
	void SetDamage(const int& damage);
	void SetStatus(bool status);
	const std::string GetName() const;
	const std::string GetElementType() const;
	const int GetDamage() const;

protected:
	std::string m_name;
	std::string m_elementType;

	float m_damage;

	bool m_status;

	std::vector<Component*> m_vComponents;
};



class ShoryuSpell : public Spells {
public:
	ShoryuSpell() {
		SetName("ShoryuSpell");
		SetElementType("Fire");
		SetDamage(25);
		SetStatus(false);
	}

private:
};