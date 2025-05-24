// @Slash

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AItem;

UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }

protected:
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EquipPressed();
	void Attack();

	// Montage Functions
	void PlayAttackMontage();

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	bool CanAttack();

private:

	ECharacterState CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	EActionState ActionState = EActionState::EAS_UnOccupied;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* AttackMontage;
};
