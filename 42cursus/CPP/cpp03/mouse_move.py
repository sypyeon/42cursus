import pyautogui
import time
import threading
import sys

class MouseMover:
    def __init__(self):
        self.running = False
        self.move_distance = 50  # 움직일 픽셀 거리
        
    def move_mouse(self):
        """마우스를 좌우로 움직이는 함수"""
        try:
            # 현재 마우스 위치 가져오기
            current_x, current_y = pyautogui.position()
            print(f"현재 마우스 위치: ({current_x}, {current_y})")
            
            # 오른쪽으로 이동
            pyautogui.moveTo(current_x + self.move_distance, current_y, duration=0.5)
            time.sleep(0.5)
            
            # 왼쪽으로 이동 (원래 위치로 복귀)
            pyautogui.moveTo(current_x, current_y, duration=0.5)
            print("마우스 움직임 완료")
            
        except Exception as e:
            print(f"마우스 이동 중 오류 발생: {e}")
    
    def start_moving(self):
        """60초마다 마우스를 움직이는 스레드 시작"""
        self.running = True
        print("마우스 자동 움직임 시작 (60초 간격)")
        print("종료하려면 Ctrl+C를 누르세요")
        
        while self.running:
            try:
                # 60초 대기
                for i in range(60, 0, -1):
                    if not self.running:
                        break
                    print(f"\r다음 움직임까지: {i}초", end="", flush=True)
                    time.sleep(1)
                
                if self.running:
                    print("\n마우스 움직임 실행 중...")
                    self.move_mouse()
                    
            except KeyboardInterrupt:
                self.stop_moving()
                break
            except Exception as e:
                print(f"\n오류 발생: {e}")
                break
    
    def stop_moving(self):
        """마우스 움직임 중지"""
        self.running = False
        print("\n마우스 자동 움직임 중지됨")

def main():
    # pyautogui 설정
    pyautogui.FAILSAFE = True  # 마우스를 화면 왼쪽 상단 모서리로 이동하면 프로그램 중지
    pyautogui.PAUSE = 0.1      # 각 pyautogui 호출 사이의 일시정지
    
    mouse_mover = MouseMover()
    
    try:
        mouse_mover.start_moving()
    except KeyboardInterrupt:
        mouse_mover.stop_moving()
    except Exception as e:
        print(f"프로그램 실행 중 오류: {e}")
    finally:
        print("프로그램 종료")

if __name__ == "__main__":
    main()