
#pragma once

namespace Acmen
{

class Camera
{

public:
	glm::vec3 mPosition;
	glm::vec3 mTarget;
	glm::vec3 mUp;

	inline Camera( ): mPosition( glm::vec3( 0.0f, 15.0f, 30.0f )), mTarget( 0.0f, 10.0f, 0.0f ), mUp( 0.0f, 1.0f, 0.0f )
		{ }

	inline ~Camera( )
		{ };

	inline glm::vec3 Right( )
		{ return glm::normalize(glm::cross(mTarget - mPosition, mUp)); }

	inline glm::vec3 Front( )
		{ return glm::normalize(mTarget - mPosition); }

	inline glm::mat4 GetMatrix( )
		{ return glm::lookAt( mPosition, mTarget, mUp ); }

	inline void SetPostition( glm::vec3 position )
		{ mPosition = position; }

	inline void SetPosition( float x, float y, float z )
		{ mPosition = glm::vec3( x, y, z ); }

	inline void SetTarget( glm::vec3 target )
		{ mTarget = target; }

	inline void SetTarget( float x, float y, float z )
		{ mTarget = glm::vec3(x, y, z); }

	inline void SetUp( glm::vec3 up )
		{ mUp = up; }

	inline void SetUp( float x, float y, float z )
		{ mUp = glm::vec3( x, y, z ); }
};

};