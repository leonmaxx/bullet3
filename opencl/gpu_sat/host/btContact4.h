#ifndef BT_CONTACT4_H
#define BT_CONTACT4_H

#include "parallel_primitives/host/btVector3.h"


ATTRIBUTE_ALIGNED16(struct) btContact4
{
	BT_DECLARE_ALIGNED_ALLOCATOR();

	btVector3	m_worldPos[4];
	btVector3	m_worldNormal;
//	float m_restituitionCoeff;
//	float m_frictionCoeff;
	unsigned short  m_restituitionCoeffCmp;
	unsigned short  m_frictionCoeffCmp;
	int m_batchIdx;

	int m_bodyAPtrAndSignBit;
	int m_bodyBPtrAndSignBit;

	int getBodyA()const {return abs(m_bodyAPtrAndSignBit);}
	int getBodyB()const {return abs(m_bodyBPtrAndSignBit);}
	bool isBodyAFixed()const { return m_bodyAPtrAndSignBit<0;}
	bool isBodyBFixed()const { return m_bodyBPtrAndSignBit<0;}
	//	todo. make it safer
	int& getBatchIdx() { return m_batchIdx; }
	const int& getBatchIdx() const { return m_batchIdx; }
	float getRestituitionCoeff() const { return ((float)m_restituitionCoeffCmp/(float)0xffff); }
	void setRestituitionCoeff( float c ) { btAssert( c >= 0.f && c <= 1.f ); m_restituitionCoeffCmp = (unsigned short)(c*0xffff); }
	float getFrictionCoeff() const { return ((float)m_frictionCoeffCmp/(float)0xffff); }
	void setFrictionCoeff( float c ) { btAssert( c >= 0.f && c <= 1.f ); m_frictionCoeffCmp = (unsigned short)(c*0xffff); }

	float& getNPoints() { return m_worldNormal[3]; }
	float getNPoints() const { return m_worldNormal[3]; }

	float getPenetration(int idx) const { return m_worldPos[idx][3]; }

	bool isInvalid() const { return (getBodyA()==0 || getBodyB()==0); }
};

#endif //BT_CONTACT4_H
