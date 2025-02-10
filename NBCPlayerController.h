#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NBCPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class PAWN3D_API ANBCPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANBCPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;

	virtual void BeginPlay() override;
};
