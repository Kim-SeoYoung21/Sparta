#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MainPawn.generated.h"

class UCapsuleComponent;
class USpringArmComponent;
class UCameraComponent;
//struct FInputActionValue;

UCLASS()
class PAWN3D_API AMainPawn : public APawn
{
	GENERATED_BODY()

public:
	AMainPawn();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	USkeletalMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	UCameraComponent* CameraComp;

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
};
