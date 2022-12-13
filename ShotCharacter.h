// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShotCharacter.generated.h"

UCLASS()
class MYSHOT_API AShotCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShotCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** called for fw/backward input**/
	void MoveForward(float Value); 

	/**called for side to side input**/
	void MoveRight(float Value);

	/** called via input at a given rate**/
	void TurnAtRate(float Rate);

	/**  called via inout to look down **/
	void LookUpAtRate(float Rate);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	/** Camera boom positioning camera behind character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Baase turn rate in degrees p s others scaling may affect final turn rate**/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	/** Base look up/dwn rate in degrees p/secs. other scalin may affect later on**/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

public:

	/** Returns camera booom subobject**/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
	
	/** returns follow camera subobject*/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }



};
