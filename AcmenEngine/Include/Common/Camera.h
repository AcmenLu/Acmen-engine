
#pragma once

namespace Acmen
{

class Camera
{

public:
	Vector3 mPosition;
	Vector3 mTarget;
	Vector3 mUp;

	inline Camera( ): mPosition( 0.0f, 0.0f, 30.0f ), mTarget( 0.0f, 0.0f, 0.0f ), mUp( 0.0f, 1.0f, 0.0f )
		{ }

	inline ~Camera( )
		{ };

	inline Vector3 Right( )
		{ return Vector3::Cross( mTarget - mPosition, mUp ).Normalize( ); }

	inline Vector3 Front( )
		{ return ( mTarget - mPosition ).Normalize( ); }

	inline Matrix4 GetMatrix( )
		{ return Matrix4::CreateLookAtRH( mPosition, mTarget, mUp ); }

	inline void SetPostition( Vector3 position )
		{ mPosition = position; }

	inline void SetTarget( Vector3 target )
		{ mTarget = target; }

	inline void SetUp( Vector3 up )
		{ mUp = up; }
};

};