#include "Spells.h"

void Spells::SetName(const std::string& name) {

	m_name = name;
}

void Spells::SetElementType(const std::string & name) {

	m_elementType = "Fire";
}

void Spells::SetDamage(const int & damage) {

	m_damage = damage;
}

void Spells::SetStatus(bool status) {

	m_status = status;
}

const std::string Spells::GetName() const {

	return m_name;
}

const std::string Spells::GetElementType() const {

	return m_elementType;
}

const int Spells::GetDamage() const {

	return m_damage;
}
